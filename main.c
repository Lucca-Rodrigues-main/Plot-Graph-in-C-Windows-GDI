#define preto_rgb_          RGB(0,0,0)
#define azul_rgb_           RGB(0,0,255)
#define verde_rgb_          RGB(0,255,0)
#define ciano_rgb_          RGB(0,255,255)
#define vermelho_rgb_       RGB(255,0,0)
#define magenta_rgb_        RGB(255,0,255)
#define marrom_rgb_         RGB(150,75,0)
#define cinza_claro_rgb_    RGB(211,211,211)
#define cinza_escuro_rgb_   RGB(169,169,169)
#define azul_claro_rgb_     RGB(173,216,230)
#define verde_claro_rgb_    RGB(144,238,144)
#define ciano_claro_rgb_    RGB(224,255,255)
#define vermelho_claro_rgb_ RGB(255,204,203)
#define magenta_claro_rgb_  RGB(255,128,255)
#define amarelo_rgb_        RGB(255,255,0)
#define branco_rgb_         RGB(255,255,255)

/* Coordenadas() preenche vetores com coordenadas para que os mesmos possam ser usados
na função Plot()

Exemplos de funcoes para plotar:

x[i]
-x[i]
abs(x[i])
((pow((double)x[i],2.0))-(20.0*(double)x[i])-50.0)/10.0
50.0*sin((double)x[i]/5.0)
sqrt(20.0*(double)x[i])
exp((double)x[i]/5.0)
(log10((double)x[i]*50.0))*5.0
(sin((double)x[i])/23.0*(pow((double)x[i], 2.0)))
fabs(50.0*sin((double)x[i]/5.0))
20.0*exp(cos((double)x[i]/5.0)) - 20.0*exp(sin((double)x[i]/5.0))
(100.0/M_PI)*asin(sin((M_PI*(double)x[i])/25.0))
(100.0/(pow(100.0, (100.0*sin((-0.1)*(double)x[i])))+1.0))-(100.0/2.0) */

#define Coordenadas(x, y, indxOp, xStartVal, xIncrm, pntsQtd)                                       \
do {                                                                                                \
    x = (int*)malloc(10*sizeof(int));                                                               \
    y = (int*)malloc(10*sizeof(int));                                                               \
    for(int aloc_ = 10*sizeof(int), xVal_ = xStartVal, i = 0; i < pntsQtd; i++, xVal_+=xIncrm)      \
    {                                                                                               \
        if(i >= (aloc_/sizeof(int))) {                                                              \
            aloc_ += 10*sizeof(int);                                                                \
            x = (int*)realloc(x, aloc_);                                                            \
            y = (int*)realloc(y, aloc_);                                                            \
        }                                                                                           \
        x[i] = xVal_;                                                                               \
        y[i] = indxOp;                                                                              \
    }                                                                                               \
} while (0)

#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef struct
{
    int widthLine;
    int lineStyle;
    int originX;
    int originY;
    int lenAbscisRL;
    int lenOrdinRL;
    COLORREF lineColor;
    COLORREF axisColor;
} SCREEN;

int Plot(int* x, int* y, unsigned pntsQtd, SCREEN S); // Desenha uma forma de onda

int main()
{
    int *x, *y;
    SCREEN screen1 =
    {
        .widthLine = 2,
        .lineStyle = PS_SOLID,
        .originX = 100,
        .originY = 100,
        .lenAbscisRL = 100,
        .lenOrdinRL = 100,
        .lineColor = vermelho_rgb_,
        .axisColor = branco_rgb_
    };

    // Gerar coordenadas para uma onda senoidal
    Coordenadas(x, y, 50.0f*sin((double)x[i]/5.0f), 0, 2, 50);

    // Desenha o grafico
    Plot(x, y, 50, screen1);

    free(x);
    free(y);
    x = NULL;
    y = NULL;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    getchar();
    return 0;
}

int Plot(int* x, int* y, unsigned pntsQtd, SCREEN S)
{
    if((x == NULL) || (y == NULL)){
        return 1;
    }

    HWND console = GetConsoleWindow();
    if(console == NULL) {
        // GetConsoleWindow() falhou
        return 1;
    }

	HDC hdc = GetDC(console);
	if(hdc == NULL) {
        // GetDC() falhou
        return 1;
    }

	for(int i = 0; i < pntsQtd; i++){
        if(x[i] >= 0 && y[i] >= 0){
            // Primeiro quadrante
            if((x[i] > S.lenAbscisRL) || (y[i] > S.lenOrdinRL)){
                pntsQtd--;
                for(int j = i; j < pntsQtd; j++){
                    x[j] = x[j+1];
                    y[j] = y[j+1];
                }
                i--;
            } else{
                x[i] += S.originX;
                y[i] = S.originY - y[i];
            }
        } else if(x[i] <= 0 && y[i] >= 0){
            // Segundo quadrante
            if((x[i] < -S.lenAbscisRL) || (y[i] > S.lenOrdinRL)){
                pntsQtd--;
                for(int j = i; j < pntsQtd; j++){
                    x[j] = x[j+1];
                    y[j] = y[j+1];
                }
                i--;
            } else{
                x[i] = S.originX + x[i];
                y[i] = S.originY - y[i];
            }
        } else if(x[i] <= 0 && y[i] <= 0){
            // Terceiro quadrante
            if((x[i] < -S.lenAbscisRL) || (y[i] < -S.lenOrdinRL)){
                pntsQtd--;
                for(int j = i; j < pntsQtd; j++){
                    x[j] = x[j+1];
                    y[j] = y[j+1];
                }
                i--;
            } else{
                x[i] = S.originX + x[i];
                y[i] = S.originY - y[i];
            }
        } else if(x[i] >= 0 && y[i] <= 0){
            // Quarto quadrante
            if((x[i] > S.lenAbscisRL) || (y[i] < -S.lenOrdinRL)){
                pntsQtd--;
                for(int j = i; j < pntsQtd; j++){
                    x[j] = x[j+1];
                    y[j] = y[j+1];
                }
                i--;
            } else{
                x[i] += S.originX;
                y[i] = S.originY - y[i];
            }
        }
	}

	// Traçando as retas que irão compor a forma de onda

	SelectObject(hdc, CreatePen(S.lineStyle, S.widthLine, S.lineColor));

    for(int i = 0; i < (pntsQtd - 1); i++){
        MoveToEx(hdc, x[i], y[i], NULL);
        LineTo(hdc, x[i+1], y[i+1]);
    }

    // Traçando as retas que correspondem aos eixos X e Y

    SelectObject(hdc, CreatePen(PS_SOLID, 1, S.axisColor));

    MoveToEx(hdc, S.originX, S.originY - S.lenOrdinRL, NULL);
    LineTo(hdc, S.originX, S.originY + S.lenOrdinRL);

    MoveToEx(hdc, S.originX - S.lenAbscisRL, S.originY, NULL);
    LineTo(hdc, S.originX + S.lenAbscisRL, S.originY);

    if(!ReleaseDC(console, hdc)){
        // ReleaseDC() falhou
        return 1;
    }

    return 0;
}
