# function_pointer_type
demo function_pointer type  
Use std::set to demo function pointer type .  
The benefit is customized comparition ( function pointer)
can easily ordered according to the comparision function.


The function pointer (fp) determines the comparison criteria for the set.  
The set remains ordered according to the comparison function provided at the time of creation.  
Changing the comparator allows you to create sets with different ordering criteria for the same type (Person in this case).  
This flexibility makes std::set with a custom comparator useful when you want to enforce specific ordering rules.  
