# CALORIE CALCULATOR
####  Video Demo:  <https://www.youtu.be/FvYc8MN73Bg>
####  Description: You can learn two things from this project. Whether You can calculate the food calories that you input or learn calorie needs per day.
This project has one folder called "project" and six files in it.
1. project.py
2. test_project.py
3. calorie-needs.pdf
4. calories.csv
5. requirements.txt
6. README.md

## 1. project.py
This file has the program code. It has one main function and four other functions to use main funtion.
Pseudocode:
    - Import libraries
    - Upload csv file that have food calories data
    - Convert the food calories data to dictionary for ease of use
    - Upload pdf about calorie needs per day
    - Convert pdf to a pandas dataframe
    - Create a function that can calculate the calorie needs
    - Create inputs in main functions
    - Get the inputs and show the requested information
## 2. test_project.py
This file was created to test the main project. It has four function to test every funtion project has.

## 3. calorie-needs.pdf
This file used to find out what a person needs calorie per day.
Source: Dietary Guidelines for Americans, 2010

## 4. calories.csv
This file contains the information about food calories.
Source: Calories in Food Items (per 100 grams) dataset on kaggle
## 5. requirements.txt
This file has the libraries I used.
    - pandas
    - pdfplumber
    - sys
    - pytest

## 6. README.md
This file explains this project.

## Installation
    pip install pandas
    pip install pdfplumber
    pip install pytest


## Why I choose pdfplumber?
There are lots of program can extract pdf file in python. Im my case I try to use PyPDF2 and tabula-py but these didn't work as I wanted. I discovered pdfplumber. It was useful and working great.
    Basic example:

    import pdfplumber

    with pdfplumber.open("path/to/file.pdf") as pdf:
        first_page = pdf.pages[0]
        print(first_page.chars[0])

In this project:

    def calorie_needs_data(path):
        pdf = pdfplumber.open(path)
        page = pdf.pages[0]

        #exctact table as a nested list
        data=page.extract_table()

        # clean the data
        data2=[[ j for j in i if j != None and j != "" ] for i in data][5:]

        # Arrange the headers
        data2[0]=["Age", "Male-Sedentary", "Male-Moderately Active", "Male-Active", "Female-Sedentary", "Female-Moderately Active", "Female-Active"]

        #convert to the dataframe
        return pd.DataFrame(data2[1:], columns=data2[0])

## Follow me
| Social Media | LINK |
| ------ | ------ |
| Github | https://github.com/akash2061 |
