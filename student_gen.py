import names
import json
import random

GENDER = ['male', 'female', '']

data = {}
data["students"] = []
for i in range(1000):
    stu = {}
    gender = random.randint(1, 3)
    stu["first_name"] = names.get_first_name(gender=GENDER[gender - 1])
    stu["last_name"] = names.get_last_name()
    stu["gender"] = str(gender)
    stu["age"] = str(random.randint(18, 25))
    stu["stu_id"] = "CST1709" + str(random.randint(0, 1000))
    data["students"].append(stu)

with open("data.json", 'w') as file:
    json.dump(data, file)
