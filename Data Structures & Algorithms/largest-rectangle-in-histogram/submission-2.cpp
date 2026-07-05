class Solution {
public:
    struct Rectangle {
        int height;
        int width;

    };


    int largestRectangleArea(vector<int>& heights) {
        // pusheo las alturas
        // Si la altura actual es más chica que la última
        // el rectángulo que pueda formar a partir de ahora está limitado por este
        // y este siempre va a querer seguir lo que ya venía construyendo
        // Notar que sólo la altura me alcanza para calcular el área del nuevo rectángulo a considerar
        // en el caso que la altura sea mayor
        size_t size = heights.size();
        vector<int> expansionLeft(size);
        vector<int> expansionRight(size);
        stack<Rectangle> rectangleLeft;
        stack<Rectangle> rectangleRight;

        for (size_t i = 0; i < size; i++) {
            if (i == 0) {
                rectangleLeft.push(Rectangle{heights[i], 1});
                expansionLeft[i] = 0;
                
                rectangleRight.push(Rectangle{heights[size - i - 1], 1});
                expansionRight[size - i - 1] = 0;

            } else {
                //Hacia izquierda 
                int possibleWidth{0};
                while (!rectangleLeft.empty() && rectangleLeft.top().height >= heights[i]) {
                    Rectangle prevLargestRectangleLeft = rectangleLeft.top();
                    rectangleLeft.pop();
                    possibleWidth += prevLargestRectangleLeft.width;
                }
                rectangleLeft.push(Rectangle {heights[i], possibleWidth + 1});
                expansionLeft[i] = possibleWidth;

                //Hacia derecha 
                possibleWidth = 0;
                while (!rectangleRight.empty() && rectangleRight.top().height >= heights[size - i - 1]) {
                    Rectangle prevLargestRectangleRight = rectangleRight.top();
                    rectangleRight.pop();
                    possibleWidth += prevLargestRectangleRight.width;
                }
                rectangleRight.push(Rectangle {heights[size - i - 1], possibleWidth + 1});
                expansionRight[size - i - 1] = possibleWidth;
            }
        }  

        int maxArea{};
        for (size_t i = 0; i < size; i++) {
            int currArea = heights[i] * (expansionLeft[i] + expansionRight[i] + 1);
            maxArea = max(currArea, maxArea);
        }

        return maxArea;
    }
};
