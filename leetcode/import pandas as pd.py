import pandas as pd

inputMatrix_1 = [[1, 7, 3],
   [1,  2, 4],
   [1,  22, 32]]

inputMatrix_2 = [[1, 0, 1],
   [21, 15, 31],
   [23, 31, 2]]


df_1 = pd.DataFrame(data=inputMatrix_1)

df_2 = pd.DataFrame(data=inputMatrix_2)


print("inputMatrix_1:")
print(df_1)


print("The dimensions(shape) of input matrix 1:")
print(df_1.shape)
print()


print("inputMatrix_2:")
print(df_2)


print("The dimensions(shape) of input matrix 2:")
print(df_2.shape)
print()


result_mult = df_1.dot(df_2)


print("Resultant Matrix after Matrix multiplication:")
print(result_mult)


print("The dimensions(shape) of Resultant Matrix:")
print(result_mult.shape)