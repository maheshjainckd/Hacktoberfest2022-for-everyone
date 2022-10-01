#%%
import warnings
warnings.filterwarnings('ignore')

import os
import numpy as np
import pandas as pd
import scipy.stats as st
import statsmodels.api as sm
import matplotlib.pyplot as plt

from sklearn import linear_model
from sklearn.metrics import mean_squared_error, r2_score, confusion_matrix, accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve
from sklearn.metrics import roc_auc_score
# %%
os.chdir('D:/machine_learning/DATA_SET/credit_risk')
df_a = pd.read_csv('credit_risk.csv')
df_a.head()
# %%
df_a.isnull().sum()
# %%
df_a.dropna(axis=0,inplace=True)
df_a.isnull().sum()
# %%
df_a.dtypes
# %%
df_a["CoapplicantIncome"] = df_a["CoapplicantIncome"].astype('float')
df_a["ApplicantIncome"] = df_a["ApplicantIncome"].astype('float')
print("AFTER CHANGING INT & OBJECT TO FLOAT")
df_a.dtypes
# %%
df_a["Dependents"].value_counts()
# %%
cleanup_nums = {
    "Married": {"Yes": 1, "No": 0},
    "Self_Employed": {"Yes": 1, "No": 0},
    "Property_Area": {"Rural":0, "Urban":1, "Semiurban":2},
    "Education": {"Graduate": 1, "Not Graduate": 0},
    "Loan_Status": { "Y": 1, "N": 0},
    "Gender": { "Male": 1, "Female": 0},
    "Dependents": { "0": 0, "1": 1, "2": 2, "3+": 3},
}

df_a.replace(cleanup_nums, inplace=True)
df_a.head()
# %%
df_corr = df_a[[ 'Gender', 'Married', 'Dependents', 'Education',
       'Self_Employed', 'ApplicantIncome', 'CoapplicantIncome', 'LoanAmount',
       'Loan_Amount_Term', 'Credit_History', 'Property_Area','Loan_Status']]

df_corr.head()
# %%
plt.imshow(df_corr.corr(), cmap=plt.cm.Blues , interpolation='nearest')
cmap='coolwarm'
plt.colorbar()
tick_marks = [i for i in range(len(df_corr.columns))]
plt.xticks(tick_marks, df_corr.columns, rotation='vertical')
plt.yticks(tick_marks, df_corr.columns)
plt.show()
#%%
boolean_col = 'Loan_Status'
cols = ['Gender','Married','Dependents','Education','Self_Employed',
        'ApplicantIncome', 'CoapplicantIncome', 'Credit_History'
        ]

xTrain = df_a[cols].values
yTrain = df_a[boolean_col].values
# %%
st.chisqprob = lambda chisq, df: st.chi2.sf(chisq, df)

model = sm.Logit( yTrain, xTrain )
result = model.fit()
result.summary( xname=cols, yname=boolean_col,title='Logit Model', alpha=1)
# %%
def calculate_accuracy( predictions, real):
    correct = 0
    for i in range(len(predictions)):
        if round(predictions[i]) == round(real[i]):
            correct += 1
    return correct * 1.0 / len(predictions)
# %%
train_predictions = result.predict(xTrain)

train_accuracy = calculate_accuracy( train_predictions, yTrain )
print("Train Accuracy: ", train_accuracy * 100 )
# %%
train_predictions = (train_predictions > 0.5) 
    
train_cm = confusion_matrix( yTrain, train_predictions, labels = [1.0, 0.0])
print(train_cm )
# %%
labels = ['0', '1']
cm = train_cm
fig = plt.figure()
ax = fig.add_subplot(111)
cax = ax.matshow(cm, cmap='viridis')
plt.title('Confusion matrix')
fig.colorbar(cax)
ax.set_xticklabels([''] + labels)
ax.set_yticklabels([''] + labels)

r=0
c=0
for listItem in cm:
    for cellItem in listItem: 
        ax.text(c,r, cellItem, va='center', ha='center', color='r')
        c+=1
    c=0
    r+=1
   
plt.xlabel('Actual label')
plt.ylabel('Predicted label')
plt.show()
# %%
