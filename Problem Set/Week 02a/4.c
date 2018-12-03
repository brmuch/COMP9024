/*a.In the stack ADT, elements are added to ("push") and removed from ("pop") 
  the beginning of the linked list. For a queue, we have two options: either 
  we add ("enqueue") new elements at the end and continue to take elements off 
  ("dequeue") from the beginning. Or we continue to add elements at the beginning and 
  dequeue from the end. Operating on both ends will be more efficient if we use a 
  datastructure with two pointers: one pointing to the first and one pointing to the
   last element of a list.

b.The solution is to use the queue Q to process the elements in two phases. 
  In the first phase, we iteratively pop all the elements from S and enqueue them in Q, 
  then dequeue the elements from Q and push them back onto S. As a result, 
  all the elements are now in reversed order on S. In the second phase, we again 
  pop all the elements from S, but this time we also look for the element x. 
  By again passing the elements through Q and back onto S, we reverse the reversal, 
  thereby restoring the original order of the elements on S.*/