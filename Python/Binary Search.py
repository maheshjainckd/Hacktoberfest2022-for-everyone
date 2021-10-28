""" Binary Search Algorithm 
----------------------------------------
"""
// iterative implementation of binary search in Python
def binary_search(a_list, item):
    """Performs iterative binary search to find the position of an integer in a given, sorted, list.
    a_list -- sorted list of integers
    item -- integer you are searching for the position of
    """
    first = 0
    last = len(a_list) - 1
    while first <= last:
        i = (first + last) / 2
        if a_list[i] == item:
            return ' found at position '.format(item=item, i=i)
        elif a_list[i] > item:
            last = i - 1
        elif a_list[i] < item:
            first = i + 1
        else:
            return ' not found in the list'.format(item=item)
// recursive implementation of binary search in Python
def binary_search_recursive(a_list, item):
    """Performs recursive binary search of an integer in a given, sorted, list.
    a_list -- sorted list of integers
    item -- integer you are searching for the position of
    """
    first = 0
    last = len(a_list) - 1
    if len(a_list) == 0:
        return ' was not found in the list'.format(item=item)
    else:
        i = (first + last) // 2
        if item == a_list[i]:
            return ' found'.format(item=item)
        else:
            if a_list[i] < item:
                return binary_search_recursive(a_list[i+1:], item)
            else:
                return binary_search_recursive(a_list[:i], item)