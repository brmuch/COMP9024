// Extend the BSTree ADT from the lecture (BSTree.h, BSTree.c) by an implementation of the function
// Written by Ashe Mahidadia
Tree AVLrepair(Tree t) {
   int hL = TreeHeight(left(t));
   int hR = TreeHeight(right(t));
   if ((hL - hR) > 1)
      t = rotateRight(t);
   else if ((hR - hL) > 1)
      t = rotateLeft(t);
   return t;
}

Tree deleteAVL(Tree t, Item it) {
   if (t != NULL) {
      if (it < data(t)) {
         left(t) = TreeDelete(left(t), it);
	 t = AVLrepair(t);
      } else if (it > data(t)) {
         right(t) = TreeDelete(right(t), it);
	 t = AVLrepair(t);
      } else {
         Tree new;
         if (left(t) == NULL && right(t) == NULL)
            new = NULL;
         else if (left(t) == NULL)    // if only right subtree, make it the new root             
            new = right(t);
         else if (right(t) == NULL)   // if only left subtree, make it the new root              
            new = left(t);
         else {                       // left(t) != NULL and right(t) != NULL                    
            new = joinTrees(left(t), right(t));
	    t = AVLrepair(new);
	 }
         free(t);
         t = new;
      }
   }
   return t;
}