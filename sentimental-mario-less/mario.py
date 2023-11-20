from cs50 import get_int

# Prompt the user for a positive integer between 1 and 8 (inclusive)
while True:
    n = get_int("Height: ")
    if n >= 1 and n <= 8:
        break

# Print the pyramid
for i in range(n):
    # Print spaces
    for j in range(n - i - 1):
        print(" ", end="")

    # Print left hashes
    for j in range(i + 1):
        print("#", end="")
        
    print()
