#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:

	int _Size = 0;
	T* _TempArray;

public:

	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
			return false;

		OriginalArray[Index] = Value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		for (int i = 0; i < NewSize; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;

		OriginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0)
			return false;

		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
				return i;
		}

		return -1;
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index != -1)
		{
			DeleteItemAt(Index);
			return true;
		}
		else
			return false;
	}
			
	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[Index] = Value;

		for (int i = Index + 1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i - 1];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;

		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAfter(0, Value);
		else
			InsertAt(Index - 1, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size, Value);
		else
			return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}
};

