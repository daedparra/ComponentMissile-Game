#pragma once
#include <list>
#include <string>
#include <functional>
#include <assert.h>
typedef unsigned int Hash;
extern std::hash<std::string> s_hash;

//
// a hash map
//
// 1. only stores pointers
// 2. can assume T *always* has the element "mHash" that contains the hash
//

template<class T, int SIZE>
class HashMap
{
public:

	HashMap()
	{
		// TODO: assert if SIZE isn't actually a power of two
		assert((SIZE != 0) && ((SIZE & (SIZE - 1)) == 0));
		mMask = SIZE - 1;
	}

	// TODO: insert data, return if succeeded
	bool Insert(T& data)
	{
		int index = Translate(data->mHash);
		if (data != nullptr)
		{
			mBuckets[index].push_back(data);
			return true;
		}
		return false;
	}

	// TODO: insert data, don't check to see if it already exists
	void InsertNoCheck(T& data)
	{
		int index = Translate(data->mHash);
		mBuckets[index].push_back(data);
	}

	// TODO: find the data from the hash
	T Find(Hash hash)
	{
		int index = Translate(hash);
		bool isEmpty = mBuckets[index].empty();
		if (!isEmpty)
		{
			for (T entry : mBuckets[index])
			{
				if (hash == entry->mHash)
				{
					return entry;
				}
			}
		}
		return nullptr;
	}

	// TODO: find the data from the hash (but as const)
	const T Find(Hash hash) const
	{
		int index = Translate(hash);
		bool isEmpty = mBuckets[index].empty();
		if (!isEmpty)
		{
			for (T entry : mBuckets[index])
			{
				if (hash == entry->mHash)
				{
					return entry;
				}
			}
		}
		return nullptr;
	}



	// TODO: delete the data from the hash
	void Delete(T data)
	{
		int index = Translate(data->mHash);
		T findHash = Find(data->mHash);

		if (findHash != nullptr)
		{
			mBuckets[index].remove(findHash);
		}

	}

private:

	// TODO: explain why this works
	int Translate(Hash hash) const
	{
		return (hash & mMask);
	}

private:

	Hash mMask;

	// TODO: you should use your own linked list class
	std::list<T> mBuckets[SIZE];
};