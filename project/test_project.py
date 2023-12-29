from project import calculate_calorie_needs, find_index, food_calories, calorie_needs_data
import pytest

def test_calculate_calorie_needs():
    assert calculate_calorie_needs("Male", "Active", "33")=="3,000"
    assert calculate_calorie_needs("Female", "sedentary", "45")=="1,800"
    assert calculate_calorie_needs("Female", "Moderately Active", "15")=="2,000"


def test_find_index():
    assert find_index(["2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18",["19","20"],["21","22","23","24","25"]], "16")==14
    with pytest.raises(ValueError):
        find_index(["2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18",["19","20"],["21","22","23","24","25"]], "189")


def test_food_calories():
    assert food_calories("calories.csv")["Apple"]==52

def test_calorie_needs_data():
    assert calorie_needs_data("calorie-needs.pdf").loc[25, "Male-Active"]=="2,600"
