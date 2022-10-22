Approach for solving the Question

Initially, we read the input file given and we take a vector of strings and store all strings in that vector.

Then, if the size of the word is maximum and it contains the words given in the vector, we store the size and 
compare it with every other word to find out the maximum and second maximum.

Main approach is Dynamic Programming concept. Since, the problem contains overlapping subproblems, we use DP to solve the problem.

We consider each prefix and search it in the dictionary. If the prefix is present in the dictionary, we recur for rest of the string.

Apart from this, we maintain all the indexes which have matched earlier. Then we will check the substringsfrom those indexes to the
current index. If anyone of that matches then we can divide the string upto that index.
