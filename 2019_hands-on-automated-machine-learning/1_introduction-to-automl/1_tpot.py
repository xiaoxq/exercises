#!/usr/bin/env python

import sklearn
import sklearn.datasets
import tpot


X, y = sklearn.datasets.load_digits(return_X_y=True)
X[0].reshape(8, 8)
X_train, X_test, y_train, y_test = sklearn.model_selection.train_test_split(X, y, random_state=1)

model = tpot.TPOTClassifier(generations=10, population_size=30, verbosity=2)
model.fit(X_train, y_train)

print(model.score(X_test, y_test))
model.export('my_pipeline.py')
