# Import required libraries
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten
from tensorflow.keras.datasets import mnist
from tensorflow.keras.utils import to_categorical

# Load the MNIST dataset
(X_train, y_train), (X_test, y_test) = mnist.load_data()

# Preprocess the data
X_train = X_train / 255.0  # Normalize to [0, 1]
X_test = X_test / 255.0
y_train = to_categorical(y_train, num_classes=10)  # One-hot encode the labels
y_test = to_categorical(y_test, num_classes=10)

# Define the ANN model
model = Sequential(
    [
        Flatten(input_shape=(28, 28)),  # Flatten the 28x28 images into a 1D array
        Dense(
            128, activation="relu"
        ),  # Hidden layer with 128 neurons and ReLU activation
        Dense(64, activation="relu"),  # Another hidden layer with 64 neurons
        Dense(
            10, activation="softmax"
        ),  # Output layer with 10 neurons (one for each class)
    ]
)

# Compile the model
model.compile(
    optimizer="adam",  # Optimizer
    loss="categorical_crossentropy",  # Loss function
    metrics=["accuracy"],
)  # Evaluation metric

# Train the model
model.fit(X_train, y_train, epochs=10, batch_size=32, validation_split=0.2)

# Evaluate the model
test_loss, test_accuracy = model.evaluate(X_test, y_test)
print(f"Test Accuracy: {test_accuracy * 100:.2f}%")
