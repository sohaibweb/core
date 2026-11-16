"""
--- Indexing and Slicing Strings in Python ---
[1] All data in python is object
[2] Objects Contain Elements 
[3] Every Element has Its Own Index
[4] python uses zero-based indexing (indexing starts at 0)
[5] Use square brackets to access Elements
[6] Enable Assigning parts of a strings, Tuples or lists
-----------------------------------------------------"""

# Indexing

my_string = "I Love Python"
print(my_string[0]) # prints I
print(my_string[12]) # prints n
print(my_string[-13]) # prints I
print(my_string[-1]) # prints n

# Slicing (access Multiple Elements)
# [start:End] End is not included in the output
# [start:End:Steps]

print(my_string[7:13]) # print python
print( my_string[7:]) # print python
print(my_string[:6]) # print I Love
print(my_string[0 : 5]) # print I Lov
print(my_string[:]) # full string
print(my_string[::1]) # print full string
print(my_string[::2]) # print every second character
print(my_string[::3]) # print every third character
print(my_string[::-1]) # print full string in reverse order
print(my_string[::-2]) # print every second character in reverse order
print(my_string[::-3]) # print every third character in reverse order