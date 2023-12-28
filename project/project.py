import pandas as pd
import pdfplumber
import sys


def main():
    global calorie_needs
    global real_ages
    calories=food_calories("calories.csv")



    question=input("What do you want to learn? (1 or 2)\n1- Food Calories (per 100 grams)\n2- Calorie needs per day\n")

    if question=="1":
        food_q=input("Which food calorie do you want to know?\n")
        if food_q.title() in calories.keys():
            print(str(calories[food_q.title()])+" calories")
        else:
            sys.exit("Not Found")
    elif question=="2":
        sex=input("What is your sex?\nFemale or Male?\n")
        if sex.title() not in ["Female","Male"]:
            sys.exit("Run again and please write only 'Female' or 'Male'")
        activity=input("Choose your weekly activity?\nSedentary or Moderately Active or Active\n")
        if activity.title() not in ["Sedentary", "Moderately Active", "Active"]:
            sys.exit("Invalid input. Run again and please choose one of 'Sedentary or Moderately Active or Active'")
        age=int(input("How old are you?\n"))

        print("\nYou need "+str(calculate_calorie_needs(sex,activity, age))+" calories per day.\n")
        popup_message="Warning: If you're pregnant or breast-feeding, are a competitive athlete, or have a metabolic disease, such as diabetes, the calorie calculator may overestimate or underestimate your actual calorie needs."
        print(popup_message)

    else:
        sys.exit("Invalid. Run again and please write only number 1 or 2.")


def calculate_calorie_needs(sex, activity, age):

    sex=sex.title()
    activity=activity.title()

    calorie_needs=calorie_needs_data("calorie-needs.pdf")
    real_ages=["2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18",["19","20"],["21","22","23","24","25"],["26","27","28","29","30"],["31","32","33","34","35"],["36","37","38","39","40"],["41","42","43","44","45"],["46","47","48","49","50"],["51","52","53","54","55"],["56","57","58","59","60"],["61","62","63","64","65"],["66","67","68","69","70"],["71","72","73","74","75"],["76","77","78","79","80"]]

    try:
        index=find_index(real_ages, str(age))
    except ValueError:
        sys.exit("Out of range. Try below 80.")

    else:
        choice=sex+"-"+activity
        calorie = calorie_needs.loc[index,choice]
    return calorie

def calorie_needs_data(path):
    pdf = pdfplumber.open(path)
    page = pdf.pages[0]
    data=page.extract_table()  #exctacting table as a nested list
    data2=[[ j for j in i if j != None and j != "" ] for i in data][5:]
    data2[0]=["Age", "Male-Sedentary", "Male-Moderately Active", "Male-Active", "Female-Sedentary", "Female-Moderately Active", "Female-Active"]

    #converting the dataframe
    return pd.DataFrame(data2[1:], columns=data2[0])

def food_calories(path):
    data=pd.read_csv(path)

    #get rid of unnecessary columns
    data.drop(['FoodCategory'], axis=1, inplace=True)
    data.drop(["KJ_per100grams"], axis=1, inplace=True)
    data.drop(["per100grams"], axis=1, inplace=True)

    #making cal and kj to an int and crop the text as "cal" and "kJ"
    data["Cals_per100grams"]=list(map(lambda i:int(i[:-3]), data.Cals_per100grams))

    #converting the dataframe to a dictionary
    return dict(zip(data.FoodItem, data.Cals_per100grams))

def find_index(mylist, char):
    for sub_list in mylist:
        if char in sub_list:
            return mylist.index(sub_list)
    raise ValueError("'{char}' is out of range. Try below 80".format(char = char))



if __name__ == "__main__":
    main()

