#!/usr/bin/env python

import autosklearn.classification
import sklearn
import sklearn.datasets


X, y = sklearn.datasets.load_digits(return_X_y=True)
X[0].reshape(8, 8)
X_train, X_test, y_train, y_test = sklearn.model_selection.train_test_split(X, y, random_state=1)

automl = autosklearn.classification.AutoSklearnClassifier()
automl.fit(X_train, y_train)
y_hat = automl.predict(X_test)

print("Accuracy score", sklearn.metrics.accuracy_score(y_test, y_hat))
