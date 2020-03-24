#include <stdlib.h>
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }
	  
      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }

      vector(vector<T> &other) { 
        s=other.s;
	if(s==0)
	   v=NULL;
	else
	   v=new class v[s];
      }

      void operator=(vector<T> &other) {
	 for(int i=0; i<s; i++)
	   delete v[i];
	 delete [] v;
	 s=other.s; 
      }

      T operator[] (int x) {
        return *(v)+x;
      }

      T at(int x) {
      
      }
     
};
