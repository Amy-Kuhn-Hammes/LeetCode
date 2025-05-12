#include <stdio.h>

float ReLu(float x) {
    if(x < 0) return 0;
    return x;
}

float derivadaReLu(float x) {
    if(x < 0) return 0;
    return 1;
}

float calcYi(float input, float w, float b) {
    return ReLu(input * w + b);
}

float calcPredicted(float w1, float w2, float w3, float w4, float b1, float b2, float b3, float input) {
    return (ReLu(input * w1 + b1) * w3 + ReLu(input * w2 + b2) * w4) + b3;
}

float derivadaPrimeiroPesos(float observed, float predicted, float w3, float input, float w1, float b1) {
    return -2 * (observed - predicted) * w3 * derivadaReLu(input * w1 + b1) * input;
}

float derivadaPrimeiroVies(float observed, float predicted, float w3, float w1, float b1, float input) {
    return -2 * (observed - predicted) * w3 * derivadaReLu(input * w1 + b1);
}

float derivadaB3(float observed, float predicted) {
    return -2 * (observed - predicted);
}

float derivadaSegundoPesos(float observed, float predicted, float Yi) {
    return -2 * (observed - predicted) * Yi;
} 

int normaliza(float x) {
    if(x <= 0.5) return 0;
    return 1;
}

float absolute(float x) {
    if(x < 0) return x*-1;
    return x;
}

int main() {

    float database[10][2] = {{0, 0}, {0.1, 0}, {0.043, 0}, {0.45, 1}, {0.50, 1}, {0.46, 1}, {0.52,1}, {0.99, 0}, {1,0},{0.89,0}};
    int databaseSize = 10;

    float w1 = 2.74, w2 = 1.13, w3 = 0.36, w4 = 0.63, b1 = 0, b2 = 0, b3 =0;
    float taxaAprendizado = 0.01, a, ans;
    int count = 0;

    while(1) {
        float tempW1 = 0, tempW2 = 0, tempW3 = 0, tempW4 = 0, tempB1 = 0, tempB2 = 0, tempB3 =0;

        //somatorio
        for(int i = 0; i < databaseSize; i++) {
            float predicted = calcPredicted(w1, w2, w3, w4, b1, b2, b3, database[i][0]);

            tempW1 += derivadaPrimeiroPesos(database[i][1], predicted, w3, database[i][0], w1, b1);
            tempW2 += derivadaPrimeiroPesos(database[i][1], predicted, w4, database[i][0], w2, b2);

            tempB1 += derivadaPrimeiroVies(database[i][1], predicted, w3, w1, b1, database[i][0]);
            tempB2 += derivadaPrimeiroVies(database[i][1], predicted, w4, w2, b2, database[i][0]);

            tempW3 += derivadaSegundoPesos(database[i][1], predicted, calcYi(database[i][0], w1, b1));
            tempW4 += derivadaSegundoPesos(database[i][1], predicted, calcYi(database[i][0], w2, b2));

            tempB3 += derivadaB3(database[i][1], predicted);
        }

        w1 -= tempW1 * taxaAprendizado;
        w2 -= tempW2 * taxaAprendizado;
        w3 -= tempW3 * taxaAprendizado;
        w4 -= tempW4 * taxaAprendizado;
        b1 -= tempB1 * taxaAprendizado;
        b2 -= tempB2 * taxaAprendizado;
        b3 -= tempB3 * taxaAprendizado;
            printf("\n%d\n\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n", count, w1, w2, w3, w4, b1, b2,b3);
            printf("\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n", tempW1, tempW2, tempW3, tempW4, tempB1, tempB2,tempB3);

        if(absolute(tempB1) + absolute(tempB2) + absolute(tempB3) + absolute(tempW1) + absolute(tempW2) + absolute(tempW3) + absolute(tempW4) * taxaAprendizado < taxaAprendizado*7 || count > 3) {

            break;
        }
        count += 1;

    }
        return 0;
    printf("Coloque um valor entre 0 e 1 indicando a dose\n");
    while(1) {
        
        scanf("%f", &a);
        ans = calcPredicted(w1, w2, w3, w4, b1, b2, b3, a);
        if(normaliza(ans))
            printf("Para um dose de %f e previsto que funcione! :) (chance de %f%%)\n", a, 100*ReLu(ans));
        else 
            printf("Para um dose de %f e previsto que nao funcione! :( (chance de %f%%)\n", a, 100*ReLu(ans));
    }

}