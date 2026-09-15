import sys
import pandas as pd
import joblib
import os

try:
    if len(sys.argv) != 8:
        raise ValueError(
            "Expected 7 inputs: chest_pain breathing_problem bleeding fever high_fever severe_pain age"
        )
    chest_pain = int(sys.argv[1])
    breathing_problem = int(sys.argv[2])
    bleeding = int(sys.argv[3])
    fever = int(sys.argv[4])
    high_fever = int(sys.argv[5])
    severe_pain = int(sys.argv[6])
    age = int(sys.argv[7])
    symptoms = [
        chest_pain,
        breathing_problem,
        bleeding,
        fever,
        high_fever,
        severe_pain
    ]
    for value in symptoms:
        if value not in [0, 1]:
            raise ValueError("Symptom inputs must be either 0 or 1")
    if age < 0 or age > 120:
        raise ValueError("Age must be between 0 and 120")
    model_path = "AI/urgency_model.pkl"
    if not os.path.exists(model_path):
        raise FileNotFoundError(
            "urgency_model.pkl not found. Train the model first."
        )
    model = joblib.load(model_path)
    data = pd.DataFrame(
        [[
            chest_pain,
            breathing_problem,
            bleeding,
            fever,
            high_fever,
            severe_pain,
            age
        ]],
        columns=[
            "chest_pain",
            "breathing_problem",
            "bleeding",
            "fever",
            "high_fever",
            "severe_pain",
            "age"
        ]
    )
    priority = model.predict(data)[0]
    print(int(priority))
except ValueError as e:
    print("Error:", e)
except FileNotFoundError as e:
    print("Error:", e)
except Exception as e:
    print("Prediction error:", e)