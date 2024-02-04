# Bubble Sort 
# Bubble Sort is a simple sorting algorithm that repeatedly iterates through the list,
# compares adjacent elements, and swaps them if they are in the wrong order. 
# list iteration is repeated until the list is sorted.

def bubble_sort(elements):
    # Iterate through each element in the list
    for i in range(len(elements)):
        # Flag to check if any swaps are made in this iteration
        found_swap = False
        # Compare and swap adjacent elements if they are in the wrong order
        for j in range(len(elements) - 1):
            if elements[j] > elements[j + 1]:
                # Swap elements
                temp = elements[j + 1]
                elements[j + 1] = elements[j]
                elements[j] = temp
                found_swap = True

        # If no swaps were made in this iteration, the list is already sorted
        if not found_swap:
            print(f'Found swap in {i + 1} iterations out of {len(elements)}.')
            break

    return elements

# Example usage
elements = [4, 6, 1, 10, 3, 0, 15, -2, 13, 21, 6, 8, 2]
sorted_elements = bubble_sort(elements.copy())
print(f'Before: {elements}\nAfter: {sorted_elements}')