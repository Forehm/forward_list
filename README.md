# forward_list

It is just a simple realisation of forward_list from STL. Many methods from original STL container absent here, but it is still quite interesting to read to understand how this container works :)  
I update it and try to do it better :)
It requires C++14 and x86
Functionality:
1) MyList() - default constructor
2) ~MyList() - destructor
3) array like operator T& operator [](const int index) - returns the element via index
4) GetSize() - return the size of the lis
5) pop_front() - erases the first element
6) pop_back() - erases the last element
7) clear() - erases all elements
8) push_front(*T data*) - puts the element data in the beginning of the list
9) push_back(*T data*) - puts the element data in the end of the list
10) insert(*T data, const int index*) puts the element data in the position before index
