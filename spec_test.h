template<class T1, class T2, int I>
class A {};            // primary template
 
template<class T, int I>
class A<T, T*, I> {};  // #1: partial specialization where T2 is a pointer to T1
 
template<class T, class T2, int I>
class A<T*, T2, I> {}; // #2: partial specialization where T1 is a pointer
 
template<class T>
class A<int, T*, 5> {}; // #3: partial specialization where T1 is int, I is 5,
                        //     and T2 is a pointer
 
template<class X, class T, int I>
class A<X, T*, I> {};   // #4: partial specialization where T2 is a pointer

template<int I>
class B{
public:
    int daj(){
        return 3;
    }
    
};

template<>
class B<5>{};

template<class T>
class Matrix
{
   void foo(T x)
   {
       //do something for a T variable.
   }
};

// must mark this inline to avoid ODR violations
// when it's defined in a header
template<> inline void Matrix<int>::foo(int x)
{
     //do something for an int variable.
}