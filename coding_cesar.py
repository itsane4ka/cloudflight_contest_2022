# pass processing

def out_red(text):
    print("\033[31m {}".format(text))


username = str(input("enter username "))
password = str(input("enter password "))

# check length
if len(username) > 10 or len(password) > 10:
    exit("error length")
else:
    print("1.length is okay!", end="\n")
    if username.islower() and password.islower():
        print(username + " " + password)
    else:
        # now lets delete upper symbols
        for i in range(0, len(username)):
            if username[i].isupper():
                username = username[0:i] + chr(ord(username[i]) + 32) + username[i + 1:]
        for i in range(len(password)):
            if password[i].isupper():
                password = password[0:i] + chr(ord(password[i]) + 32) + password[i + 1:]
        print("username:" + username + ", password: " + password + "\n")
common_str = username + " " + password

# check for digits
for i in range(len(common_str)):
    if common_str[i].isdigit():
        exit("error: digit found")

# now lets say if the password is weak
counter = 97
while counter < 122:
    percentage = (password.count(chr(counter)) / (len(password))) * 100
    # print(chr(counter), percentage, sep=" ", end="\n")
    if percentage > 50:
        exit("weak password")
    counter += 1

# now lets code it
for i in range(len(common_str)):
    if common_str[i] != ' ':
        if ord(common_str[i]) + 2 < 122:
            common_str = common_str[0:i] + chr((ord(common_str[i]) + 2) % 123) + common_str[i + 1:]
        else:
            common_str = common_str[0:i] + chr((ord(common_str[i]) + 2) % 123 + 97) + common_str[i + 1:]
out_red(common_str)
# print(common_str)

# dividing str back
position = common_str.find(" ")
common_str = common_str[0:position] + "\n" + common_str[position + 1:]

# now lets put it in a file
f = open('info.txt', 'wt')
f.write(common_str)
