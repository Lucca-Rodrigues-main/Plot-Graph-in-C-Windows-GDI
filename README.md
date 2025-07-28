# Plot-Graph-in-C-Windows-GDI
A tool to plot mathematical functions and waveforms directly in the Windows console using GDI for quick data visualization, featuring customizable axes, line styles, and colors.

---

### **Introdução**

Este projeto implementa uma ferramenta simples para plotar gráficos cartesianos diretamente no console do Windows, utilizando funções da API do Windows (GDI). A biblioteca permite desenhar formas de onda, eixos coordenados e personalizar cores, estilos de linha e escalas.

**Por que isso é interessante?**
- **Simplicidade:** Gera gráficos sem dependências externas, apenas com a API do Windows.
- **Customização:** Controle sobre espessura, cor e estilo das linhas, além dos eixos.
- **Didático:** Útil para visualizar funções matemáticas ou dados em tempo real em ambientes limitados.
É ideal para projetos educacionais, protótipos ou quem deseja entender o básico de renderização gráfica no Windows.

### **Função `Plot()`**
Desenha um gráfico cartesiano no console do Windows usando as funções `MoveToEx()` e `LineTo()` da API GDI.

**Parâmetros:**
- **`int *x` e `int *y`**: Vetores contendo as coordenadas a serem plotadas. Alocados dinamicamente pela macro `Coordenadas()`.
- **`unsigned pntsQtd`**: Número total de pontos a serem desenhados.
- **`SCREEN S`**: Estrutura de configuração do gráfico, contendo:
  - **`widthLine`** (espessura da linha do gráfico).
  - **`lineStyle`** (estilo da linha, ex: `PS_SOLID`, `PS_DASH`).
  - **`originX` e `originY`** (posição da origem do plano cartesiano na tela).
  - **`lenAbscisRL` e `lenOrdinRL`** (comprimento dos eixos X e Y em ambas direções).
  - **`lineColor`** (cor da linha do gráfico, definida via `RGB()`).
  - **`axisColor`** (cor dos eixos X e Y).

---

### **Macro `Coordenadas()`**
Aloca dinamicamente e preenche vetores `x` e `y` com valores calculados a partir de uma função matemática.

**Parâmetros:**
- **`x` e `y`**: Ponteiros para os vetores que armazenarão as coordenadas.
- **`indxOp`**: Expressão matemática que define `y[i]` em função de `x[i]`.
- **`xStartVal`**: Valor inicial de `x`.
- **`xIncrm`**: Incremento aplicado a `x` a cada iteração.
- **`pntsQtd`**: Número total de pontos a serem gerados.

---

### **Exemplos**

Plotagem de uma senoide comum:

<img width="201" height="201" alt="image" src="https://github.com/user-attachments/assets/5a73f6ec-6761-4373-af86-2010fd689358" />

Plotagem de uma onda quadrada:

<img width="201" height="200" alt="image" src="https://github.com/user-attachments/assets/5ccd49fe-b3eb-4485-bbac-afc1d759a654" />

Plotagem de uma onda triangular:

<img width="201" height="200" alt="image" src="https://github.com/user-attachments/assets/d181bb77-38f0-41f0-93f9-a93b0c9054e4" />

Plotagem de um coração (2 funções condicionadas):

<img width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/437b5d41-0d33-4bc1-af48-0b49a2976a28" />

Plotagem de... Algo bem estranho:

<img width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/1e4e9744-3b78-4733-9408-4fe0b03e37da" />
