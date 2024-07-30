y = dataset["style"]
x = dataset.drop("style",axis = 1)

from sklearn.model_selection import train_test_split
x_treino, x_teste, y_treino, y_teste = train_test_split(x, y, test_size = 0.30)

from sklearn.ensemble import ExtraTreesClassifier
modelo = ExtraTreesClassifier()
modelo.fit(x_treino, y_treino)

Acuracia = pandas.DataFrame([modelo.score(x_teste, y_teste)])
dataset['Previsao'] = modelo.predict(x)