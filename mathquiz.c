#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int numQuestions = 5;
    int score = 0;

    srand(time(NULL));

    printf("\n\n\t\t\tWelcome to the Math Quiz Game!\n");

    for (int i = 1; i <= numQuestions; i++) {
        int num1 = generateRandomNumber(1, 20);
        int num2 = generateRandomNumber(1, 20);
        int operator = generateRandomNumber(1, 4);

        char operatorSymbol;
        int correctAnswer, userAnswer;

        switch (operator) {
            case 1:
                operatorSymbol = '+';
                correctAnswer = num1 + num2;
                break;
            case 2:
                operatorSymbol = '-';
                correctAnswer = num1 - num2;
                break;
            case 3:
                operatorSymbol = '*';
                correctAnswer = num1 * num2;
                break;
            case 4:
                operatorSymbol = '/';
                correctAnswer = num1 / num2;
                break;
        }

        printf("\n\t\t\tQuestion %d: What is %d %c %d?\n", i, num1, operatorSymbol, num2);
        printf("\t\t\tYour answer: ");
        scanf("%d", &userAnswer);

        if (userAnswer == correctAnswer) {
            printf("\t\t\tCorrect!\n");
            score++;
        } else {
            printf("\t\t\tIncorrect. The correct answer is %d.\n", correctAnswer);
        }
    }

    printf("\n\t\t\tQuiz completed! You got %d out of %d questions correct.\n", score, numQuestions);

    return 0;
}

