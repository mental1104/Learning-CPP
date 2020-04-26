std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;

/*********************************************************
 * By a modern complier with highlight, it's easy to find 
 * the first and the second are right, and the rest is wrong
 **********************************************************
 */