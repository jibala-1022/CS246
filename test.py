import mysql.connector
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="root",
    database="mydatabase"
)
print(mydb)

mycursor = mydb.cursor()

mycursor.execute("show databases")

for x in mycursor:
    print(x)


mycursor.execute("create table if not exists customers(name varchar(255), address varchar(255))")

mycursor.execute("show tables")
for x in mycursor:
    print(x)

print(mycursor)
print(type(mycursor))
for x in mycursor:
    print(type(x), x)

sql = "INSERT INTO \
customers (name, address) VALUES (%s, %s)"
val = ("John", "Highway 21")

mycursor.execute(sql, val)

mydb.commit()

print(mycursor.rowcount, "record inserted")
print(mycursor)
print(mycursor.rowcount)

print("Selecting")
mycursor.execute("select * from customers")

myresult = mycursor.fetchall()
for x in myresult:
    print(type(x))
