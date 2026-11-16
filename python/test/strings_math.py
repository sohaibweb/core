""" Strings Methods in Python """

# len()

my_string = "Hello World"
print("string:", my_string) # prints Hello World
print("length:", len(my_string)) # prints 11

print ('\n')
# strip() & lstrip() & rstrip()

my_string = "   Hello World   "
print("word:", my_string) # prints    Hello World
print("stripped:", my_string.strip()) # prints Hello World
print("left stripped:", my_string.lstrip()) # prints Hello World
print("right stripped:", my_string.rstrip()) # prints Hello World

my_string = "#####Hello World#####"
print("stripped:", my_string.strip("#####")) # prints HelloWorld

my_string = "#@#@Hello World#@#@"
print("stripped:", my_string.strip("#@")) # prints Hello World

print ('\n')
# title()

my_string = "my name is sohaib abu musameh I am a student at 42 irbid university"
print("word:", my_string) # prints my name is sohaib abu musameh I am a student at 42 irbid university
print("title:", my_string.title()) # prints My Name Is Sohaib Abu Musameh I Am A Student At 42 Irbid University

print ('\n')
# capitalize()

my_string = "my name is sohaib abu musameh I am a student at 42 irbid university"
print("word:", my_string) # prints my name is sohaib abu musameh I am a student at 42 irbid university
print("capitalized:", my_string.capitalize()) # prints My name is sohaib abu musameh i am a student at 42 irbid university

print ('\n')
# zfill()

a, b, c = '1', '11', '11'
print("words : '1', '11', '111'") # prints words
print("zfilled: ",a.zfill(3))
print("zfilled: ",b.zfill(3))
print("zfilled: ",c.zfill(3))

print('\n')
# upper() & lower()

a = "sohaib"
b = "SOHAIB" 

print('A : ', a.upper())
print('B : ', b.lower())