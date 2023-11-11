import cs50

def main():
    # Ask how many dollars the customer is owed
    dollars = get_dollars()

    # Convert dollars to cents
    cents = dollars_to_cents(dollars)

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = cents

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)

def get_dollars():
    while True:
        dollars = cs50.get_float("Change owed: ")
        if dollars > 0:
            return dollars

def dollars_to_cents(dollars):
    return int(dollars * 100)

def calculate_quarters(cents):
    return cents // 25

def calculate_dimes(cents):
    return cents // 10

def calculate_nickels(cents):
    return cents // 5

if __name__ == "__main__":
    main()
