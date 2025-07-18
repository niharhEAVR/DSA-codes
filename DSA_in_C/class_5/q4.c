// Question 4: The following simple code sums the values of all the nodes in a balanced binary search tree ( don’t worry about what it is, we’ll learn them later ). What is its runtime?

int sum(Node node)
{
    if (node == NULL)
    {
        return 0;
    }
    return sum(node.left) + node.value + sum(node.right);
}
