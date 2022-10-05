import pandas as pd
x = pd.Series(['Jonh','Ton','Carot','Lisa','Jackie'])
a = pd.Series([1100,2000,1000,1000,1000])
b = 50
y = a+b
data= pd.DataFrame({'Name': x, 'Income': y})
print(data)
