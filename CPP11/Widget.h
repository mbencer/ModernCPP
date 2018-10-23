#include <stdexcept>
#include <iostream>

namespace OldCpp
{
	class Widget
	{
		int bufferSize = 1000;
		int* _buffer;
		int _id = 0;
	public:
		Widget()
			: _buffer(new int[bufferSize])
		{
			_id = counter++;
			std::cout << "Ctor begins with id=" << _id << std::endl;
		}

		Widget(const Widget& widget)
			: _buffer(new int[bufferSize])
		{
			std::cout << "Copy ctor begins with copy object with id=" << widget._id << std::endl;
			memcpy(_buffer, widget._buffer, sizeof(int)*bufferSize);
		}

		Widget& operator=(const Widget& widget)
		{
			if (this == &widget)
				return *this;
			memcpy(_buffer, widget._buffer, sizeof(int)*bufferSize);

			return *this;
		}

		bool operator<(const Widget& other) const
		{
			return _id < other._id;
		}

		~Widget()
		{
			delete[] _buffer;
		}
		static int counter;
	};
	int Widget::counter = 0;
}

namespace ModernCpp
{
	class Widget
	{
		int bufferSize = 1000;
		int* _buffer;
		int _id = 0;
	public:
		Widget()
			: _buffer(new int[bufferSize])
		{
			_id = counter++;
			std::cout << "Ctor begins with id=" << _id << std::endl;
		}

		Widget(const Widget& widget)
			: _buffer(new int[bufferSize])
		{
			std::cout << "Copy ctor begins with copy object with id=" << widget._id << std::endl;
			memcpy(_buffer, widget._buffer, sizeof(int)*bufferSize);
		}

		Widget(Widget&& widget) noexcept
			: _buffer(widget._buffer), _id(widget._id)
		{
			widget._id = -1;
			widget.bufferSize = 0;
			widget._buffer = nullptr;
		}

		Widget& operator=(Widget&& source) noexcept
		{
			if(this != &source)
			{
				_buffer = source._buffer;
				_id = source._id;
				source._buffer = nullptr;
				source._id = -1;
			}
			return *this;
		}

		Widget& operator=(const Widget& widget)
		{
			if (this == &widget)
				return *this;
			memcpy(_buffer, widget._buffer, sizeof(int)*bufferSize);

			return *this;
		}

		bool operator<(const Widget& other) const
		{
			return _id < other._id;
		}

		~Widget()
		{
			delete[] _buffer;
		}
		static int counter;
	};
	int Widget::counter = 0;
}