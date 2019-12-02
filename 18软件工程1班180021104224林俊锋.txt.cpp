 
	#include <iostream> 
	#include<stdlib.h>      
	using namespace std;   
	  
	template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n);  
	  
	int main()  
	{  
	    int x = 10;  
	    int a[20];  
	    for(int i=0; i<20; i++)  
	    {  
	        a[i] = i + 1;  
	    }  
	    for(int i=0; i<20; i++)  
	    {  
	        cout<<a[i]<<" ";  
	    } 
	    cout<<endl;
	    
	    cout<<"erfen"<<x<<" xiabiaoshi£º ";  
	    cout<<BinarySearch(a,x,20)<<endl;  
	    system("pause");
		return 0;  
	}  
	  
	template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n)  
	{  
	    int left = 0;  
	    int right = n-1;  
	    while(left<=right)  
	    {  
	        int mid = (left + right)/2;  
	        if(x == a[mid])  
	        {  
	            return mid;  
	        }  
	        if(x>a[mid])  
            {  
	            left = mid + 1;  
	        }  
            else  
	        {  
	            right = mid - 1;  
	        }  
       }  
	  
    return -1;  
   }  

