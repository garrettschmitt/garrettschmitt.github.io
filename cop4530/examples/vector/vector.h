#include <algorithm>

template <typename Object>
class Vector
{
  public:
    explicit Vector( int initSize = 0 )		// constructor
      : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      { objects = new Object[ theCapacity ]; }
      
    Vector( const Vector & rhs )		// copy constructor
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    { 
        objects = new Object[ theCapacity ];
        for( int k = 0; k < theSize; ++k )
            objects[ k ] = rhs.objects[ k ];
    }
    
    Vector & operator= ( const Vector & rhs )	// copy assignment operator=
    {
        Vector copy = rhs;			// calling copy constructor
        std::swap( *this, copy );
        return *this;
    }

   ~Vector( )
      { delete [ ] objects; }

    Vector( Vector && rhs )			// move constructor
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }
   
    Vector & operator= ( Vector && rhs )		// move assignment operator=
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( theCapacity, rhs.theCapacity );
        std::swap( objects, rhs.objects );
        
        return *this;
    }
    
    bool empty( ) const
      { return size( ) == 0; }
    int size( ) const
      { return theSize; }
    int capacity( ) const
      { return theCapacity; }

    Object & operator[]( int index )
    {
	return objects[ index ];		// no error checking
    }

    const Object & operator[]( int index ) const
    {
	return objects[ index ];		// no error checking
    }
   
   void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 );		// memory allocation is expensive
        theSize = newSize;
    }

    void reserve( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *newArray = new Object[ newCapacity ];
        for( int k = 0; k < theSize; ++k )
            newArray[ k ] = std::move( objects[ k ] );

        theCapacity = newCapacity;
        std::swap( objects, newArray );
        delete [ ] newArray;
    }

   void push_back( const Object & x )			// copy x
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );			// memory allocation is expensive
        objects[ theSize++ ] = x;
    }

 void push_back( Object && x )			// move x
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }

    void pop_back( )
    {
	--theSize;
    }

    const Object & back ( ) const
    {
	return objects[ theSize - 1 ];
    }

      // Iterator stuff: not bounds checked
    typedef Object * iterator;		// defined as pointer to object, not real nested class
    typedef const Object * const_iterator;

    iterator begin( )
      { return &objects[ 0 ]; }
    const_iterator begin( ) const
      { return &objects[ 0 ]; }
    iterator end( )
      { return &objects[ size( ) ]; }
    const_iterator end( ) const
      { return &objects[ size( ) ]; }

    static const int SPARE_CAPACITY = 16;

  private:
    int theSize;	// number of actual elements
    int theCapacity;	// number of elements that can be stored without reallocating memory
    Object * objects;
};


