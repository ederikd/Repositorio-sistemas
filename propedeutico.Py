# 10. Working with datetime

import datetime
from gettext import install

x = datetime.datetime.now()

print(x)               #imprime toda la fecha y hora actual
print(x.year)          #imprime el año actual
print(x.strftime("%A")) #imprime el dia de la semana actual
print(x.strftime("%B")) #imprime el mes actual
print(x.strftime("%d")) #imprime el dia del mes
print(x.strftime("%H:%M:%S %p"))  #imprime la hora(%H), el minuto(%M), el segundo(%S), y si es am o pm (%p)

# 11. NumPy

#instala NumPy usando pip
#pip install numpy

import numpy as np


#inspeccionanado tu matriz
# Create array
a = np.arange(15).reshape(3, 5) #crea una matriz con rango de 0 a 14 de 3x5
b = np.zeros((3,5))  #crea una matriz con puros ceros de 3x5
c = np.ones( (2,3,4), dtype=np.int16 ) # crea matriz de unos y define el tipo de datos
d = np.ones((3,5)) #crea matriz de unos de 3x5


a.shape # dimension de matriz
len(b) #Longitud de matriz
c.ndim #numero de dimension de la matriz
a.size #numero de elementos de la matriz
b.dtype #tipo de datos de los elementos de la matriz
c.dtype.name #nombre del tipo de datos
c.astype(float)#convierte un tipo de matriz a otro tipo de matriz

#operaciones basicas

np.add(a,b) #suma
np.subtract(a,b) #resta
np.divide(a,d) #division
np.multiply(a,d) #multiplicacion
np.array_equal(a,b) #comparacion

#funciones agregadas

a.sum() #suma 
a.min() #valor minimo
a.mean() #media
a.max(axis=0) #valor maximo de la fila de la matriz
np.std(a) #desviacion estandar

#Manipulacion de matrices

np.transpose(a) # transponer matriz a
a.ravel() # aplanar matriz
a.reshape(5,-2) # reformar sin cambiar datos
np.append(a,b) # agragar elementos a la matriz
np.concatenate((a,d), axis=0) # cancatenar matrices
np.vsplit(a,3) # dividir matriz verticalmente en el indice 3
np.hsplit(a,5) # dividir matriz horizontalmente en el indice 5

#PANDAS

#instalar pandas,xlrd y openpyxl usando pip
#!pip install pandas
# !pip install xlrd openpyxl

import pandas as pd

#dataframe de muestra
df = pd.DataFrame({'num_legs': [2, 4, np.nan, 0],
                   'num_wings': [2, 0, 0, 0],
                   'num_specimen_seen': [10, np.nan, 1, 8]},
                   index=['falcon', 'dog', 'spider', 'fish'])
df # mostrar dataframe

#otro dataframe de muetsra usando matriz numpy con indice de fecha y hora y columna etiquetada
df1 = pd.date_range('20130101', periods=6)
df1 = pd.DataFrame(np.random.randn(6, 4), index=df1, columns=list('ABCD'))
df1 # mostrar dtaframe df1

#ver datos

df1.head(2) # ver datos principales
df1.tail(2) # ver datos inferiores
df1.index # muestra la columna de indice
df1.dtypes # inspeccionar tipos de datos
df1.describe() # muestra estadisticas rapidas de resumen de datos

#sunconjuntos, division e indexaccion

df1.T # Ttransponer datos
df1.sort_index(axis=1, ascending=False) # ordenar por un eje
df1.sort_values(by='B') # ordenar por valores
df1['A'] # seleccionar la columna A
df1[0:3] # sleccionar indice de 0 a 2
df1['20130102':'20130104'] # Seleccionar el indice que coincida con los valores
df1.loc[:, ['A', 'B']] # seleccionar en un eje multiple por etiqueta
df1.iloc[3] # Sseleccionar a traves de la posicion de los enteros pasados
df1[df1 > 0] # seleccionar valores de un dataframe donde se cumple una condicion booleana
df2 = df1.copy() # copiar el conjunto de datos df1 a df2
df2['E'] = ['one', 'one', 'two', 'three', 'four', 'three'] # agregar columna E con valores
df2[df2['E'].isin(['two', 'four'])] #usar el metodo isin para filtrar

#Datos perdidos

df.dropna(how='any') # Elimina las filas  a las que les falten los datos
df.dropna(how='any', axis=1) # elimina cualquier columna  ala que le falten datos
df.fillna(value=5) # rellena datos que faltan con valor 5
pd.isna(df) # para obtener una mascara booleana donde faltan datos

#Manejo de archivos

df.to_csv('foo.csv') # escribe en archivo CSV
pd.read_csv('foo.csv') # Lee desde el archivo CSV
df.to_excel('foo.xlsx', sheet_name='Sheet1') # Escribe en un archivo de excel
pd.read_excel('foo.xlsx', 'Sheet1', index_col=None, na_values=['NA']) # Lee desde el archivo de excel


#Gaaficando

#instalar matplotlib usando pip
#!pip install matplotlib

from matplotlib import pyplot as plt # importa un madulo de matplotlib

# generando datos aleatorios de series de tiempo
ts = pd.Series(np.random.randn(1000),index=pd.date_range('1/1/2000', periods=1000)) 
ts.head()

ts = ts.cumsum()
ts.plot() # graficar
plt.show()

# en un data frame, el metodo plot es conveniente para trazar todas las columnas con etiquetas
df4 = pd.DataFrame(np.random.randn(1000, 4), index=ts.index,columns=['A', 'B', 'C', 'D'])
df4 = df4.cumsum()
df4.head()

df4.plot()
plt.show()