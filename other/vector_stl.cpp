	template <typename T>
	class vector
	{
	    public :
 
			// constructors
			vector()
				: array_( new T[_DEFAULT_VECTOR_SIZE] ),
				  reserved_size_( _DEFAULT_VECTOR_SIZE ),
				  size_( 0 )
			{ }
 
			vector(int n) // create vector with n default elements
				: array_(new T[n] ),
				  reserved_size_( n ),
				  size_( 0 )
    		{ }
 
			// destructor
			~vector()
			{ delete[] array_; }
 
	    private :
 
		    T *array_;
			int size_;
			int reserved_size_;
	};

	void vector<T>::push_back(const T &t)
    {
        // if we've run out of space, allocate more memory
        if(size_ == reserved_size_)
        	resize(reserved_size_ + _DEFAULT_VECTOR_SIZE);

        // size_ when used as an index, points to the next position after
        // the last element in the vector
        array_[size_] = t;

        // now there is one more element in the vector, so increase the size
        size_++;
    }

    void vector<T>::resize(int n) // make the size of the internal array exactly n
    {
        if(n > reserved_size_) // if requested size is more than the current size
        {
            // allocate a new array of larger capacity
            // copy the old array to new array
            // destroy old array

            T* new_array = new T[n];
            for (int i = 0; i < size_; i++) {
            	new_array[i] = array_[i];
            }

            delete[] array_;
            array_ = new_array;
            reserved_size_ = n;
        }
    }
