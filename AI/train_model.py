import pandas as pd
from sklearn.tree import DecisionTreeClassifier
import joblib
import os

try:
    data = pd.read_csv("training_data.csv")
    required_columns = [
        "chest_pain",
        "breathing_problem",
        "bleeding",
        "fever",
        "high_fever",
        "severe_pain",
        "age",
        "priority"
    ]
    for column in required_columns:
        if column not in data.columns:
            raise ValueError(f"Missing column: {column}")
    if data.empty:
        raise ValueError("Training data is empty")
    X = data[
        [
            "chest_pain",
            "breathing_problem",
            "bleeding",
            "fever",
            "high_fever",
            "severe_pain",
            "age"
        ]
    ]
    y = data["priority"]
    model = DecisionTreeClassifier(random_state=42)
    model.fit(X, y)
    joblib.dump(model, "urgency_model.pkl")
    print("AI model trained successfully!")
    print("Model saved as urgency_model.pkl")
except FileNotFoundError:
    print("Error: training_data.csv not found")
except pd.errors.EmptyDataError:
    print("Error: training_data.csv is empty")
except ValueError as e:
    print("Error:", e)
except Exception as e:
    print("Unexpected error:", e)