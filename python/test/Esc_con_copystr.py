""" Function to print a greeting message """
def ft_hello_gardan():
    print("Hello Gardan Community!")

""" Escape characters in Python """
print("1 Hello\nWorld") # prints Hello in one line and World in the next line
print("2 Hello\tWorld") # prints Hello and World with a tab space in between
print("3 Hello\\World") # prints Hello\World
print("4 Hello\'World\'") # prints Hello'World'
print("5 Hello\"World\"") # prints Hello"World"
print("123456 42 \r Arbid") # prints World in the same line as Hello
print("\x73\x74\x72") # prints str in hexadecimal format

print ('\n')
""" concatenation of strings in Python """

masg = "My name is "
name = "Sohaib Abu Musameh "
target = "I am a student 42 irbid University!"
print(masg + name + target) # concatenates the three strings and prints them

a = "Hello \
42 \
World"

b = "I am a student \
42 \
Irbid University!"

c = "where is the \
42 \
World?"

print(a + " " + b + " " + c) # concatenates the three strings and prints them

c = "irbid"
x = 42

# print(c + x) # this will raise an error because you cannot concatenate a string and an integer
print ('\n')

""" Strings """

my_stringOne = "Hello World"
my_stringTwo = 'Hello World'

print(my_stringOne) # prints Hello World
print(my_stringTwo) # prints Hello World

my_stringThree = "Hello 'World'"
my_stringFour = 'Hello "World"'

print(my_stringThree) # prints Hello World
print(my_stringFour) # prints Hello World

my_stringFive = """one
two"""
my_stringSix = '''one
two'''

print(my_stringFive) # prints Hello World
print(my_stringSix) # prints Hello World