#!/usr/bin/env python
# coding: utf-8

# # Practical 6
# 
# Name: Vanitha K
# 
# Roll: 2019358

# Q1: Implement Multiple Linear Regression using Rormal Method and calculate RSS for the model on Advertising data.csv

# In[2]:


import numpy as np
import pandas as pd


# In[9]:


df = pd.read_csv("Advertising.csv")
x = dataset[["TV", "radio","newspaper"]]
y = dataset["sales"]

x_0 = pd.DataFrame({
    "Ones": [1 for i in range(len(x["TV"]))]})
x = pd.concat([x_0, x], axis = 1)
a = np.dot(x.T, x)
a_inverse = np.linalg.inv(a)
b = np.dot(a_inverse, x.T)
b = np.dot(b, y)

y_pred = pd.DataFrame({
    "Y-Predicted": [0 for i in range(len(x["TV"]))]
})

y_pred["Y-Predicted"]+=np.dot(b[0],x["Ones"])
y_pred["Y-Predicted"]+=np.dot(b[1],x["TV"])
y_pred["Y-Predicted"]+=np.dot(b[2],x["radio"])
y_pred["Y-Predicted"]+=np.dot(b[3],x["newspaper"])

print(y)
print(y_pred)
print(y-y_pred["Y-Predicted"])
print("Result obtained is: ", (np.sum((y-y_pred["Y-Predicted"])**2)))
print("\n\n")


# In[ ]:




