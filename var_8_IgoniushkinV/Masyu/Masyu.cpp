#include <SFML/Graphics.hpp>
#include <iostream>
#include <iostream>

enum CELL_TYPES
{
    CELL_EMPTY = 0,
    CELL_BLACK = 10,
    CELL_WHITE = 20
};

enum CELL_LINES
{
    LINE_NONE = 0,
    LINE_NE, /* north-to-east, (L) */
    LINE_SE, // south-to-east, (Г)
    LINE_SW,
    LINE_NW,
    LINE_HOR,
    LINE_VER
};

//размер шрифта, ячейки, размер, размер окна, отступ у блока, размер шрифта победы
int const font_size = 30;
int const cell_size = 50;
int const line_thickness = 4;
int const n = 10;
int const win_size = cell_size * n;
int const block_offset = 3;
int const font_size_gameover = 100;

//создаем массив для поля из массива-ответа
//заменяем все -1 на 0

void answer_to_field(int answer[][n], int field[][n], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //field[i][j] = answer[i][j];
            if (answer[i][j] >= CELL_WHITE)
                field[i][j] = CELL_WHITE;
            else if (answer[i][j] >= CELL_BLACK)
                field[i][j] = CELL_BLACK;
            else
                field[i][j] = CELL_EMPTY;
        }
    }
}

//проверка ответа
//если массивы совпадают - возвращает true
//иначе - false

bool check_ans(int answer[][n], int field[][n], int n)
{
    bool equal = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (answer[i][j] != field[i][j])
                equal = false;
        }
    }
    return equal;
}

int next_cell_state(int prev_state)
{
    int line = prev_state % 10 + 1;
    if (line > LINE_VER)
        line = LINE_NONE;
    if (prev_state >= CELL_WHITE)
    {
        if (line == LINE_VER || line == LINE_NONE)
            return (CELL_WHITE + line);
        return (CELL_WHITE + LINE_HOR);
    }
    if (prev_state >= CELL_BLACK)
    {
        if (line > LINE_NW)
            line = LINE_NONE;
        return (CELL_BLACK + line);
    }
    return (CELL_EMPTY + line);
}

int main()
{
    // 0 - пусто, -1 - блок, остальное - числа
   /*
   int answer[n][n] = { { -1, 2, 6, -1, 0, 0, 3},
                         { 0, -1, 0, 0, 0, 0, -1},
                         { 0,  0, 0, 0, -1, 0, 0},
                         { 3, -1, 0, 5, 0, -1, 4},
                         { -1, 0, 0, -1, 0, 0, 0},
                         { 0, 0, -1, 0, 0, -1, 0},
                         { 2, -1, 0, 0, 7, 4, -1} };
   */

    int answer[n][n] = {
        /*
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_WHITE, CELL_EMPTY, CELL_EMPTY, CELL_EMPTY, CELL_BLACK, CELL_EMPTY},
*/

{ CELL_EMPTY, CELL_EMPTY + LINE_SE, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_SW, CELL_EMPTY + LINE_SE, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_SW},

{ CELL_EMPTY + LINE_SE, CELL_EMPTY + LINE_NW, CELL_EMPTY, CELL_EMPTY + LINE_SE, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_NE, CELL_EMPTY + LINE_HOR, CELL_BLACK + LINE_SW, CELL_EMPTY + LINE_VER},

{ CELL_EMPTY + LINE_NE, CELL_EMPTY + LINE_HOR, CELL_BLACK + LINE_SW, CELL_EMPTY + LINE_VER, CELL_BLACK + LINE_SE, CELL_EMPTY + LINE_HOR, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_SW, CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_VER},

{ CELL_EMPTY, CELL_EMPTY, CELL_EMPTY + LINE_VER, CELL_WHITE + LINE_VER, CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_SE, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_VER},

{ CELL_BLACK + LINE_SE, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_NE, CELL_EMPTY + LINE_NW, CELL_WHITE + LINE_VER, CELL_EMPTY, CELL_EMPTY + LINE_SE, CELL_EMPTY + LINE_NW, CELL_WHITE + LINE_VER},

{ CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_SE, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_SW, CELL_EMPTY + LINE_VER, CELL_EMPTY, CELL_WHITE + LINE_VER, CELL_EMPTY + LINE_SE, CELL_EMPTY + LINE_NW},

{ CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_VER, CELL_BLACK + LINE_SE, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_NE, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_NE, CELL_EMPTY + LINE_SW},

 { CELL_WHITE + LINE_VER, CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_VER, CELL_EMPTY, CELL_BLACK + LINE_SE, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_SW, CELL_WHITE + LINE_VER},

 { CELL_EMPTY + LINE_NE, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_VER, CELL_EMPTY, CELL_EMPTY + LINE_VER, CELL_EMPTY + LINE_SE, CELL_WHITE + LINE_HOR, CELL_WHITE + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_VER},

{ CELL_EMPTY, CELL_EMPTY, CELL_BLACK + LINE_NE, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_NW, CELL_EMPTY + LINE_NE, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_EMPTY + LINE_HOR, CELL_BLACK + LINE_NW},

};

    int field[n][n] = { {0} };
    answer_to_field(answer, field, n);

    // путь к папке res
    std::string resourses = "D:/TP-lab4/var_8_IgoniushkinV/Masyu/res/";

    //создаем окно
    sf::RenderWindow window(sf::VideoMode(win_size, win_size), "Masyu", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    //достаем из папки шрифт
    sf::Font font;
    if (!font.loadFromFile(resourses + "arial.ttf"))
        return EXIT_FAILURE;

    //создаем картинку
    sf::Image image;
    image.create(win_size, win_size, sf::Color::White);

    //рисуем линии клеток
    for (int i = 0; i < win_size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int zero = j * cell_size;
            image.setPixel(zero, i, sf::Color::Black);
            image.setPixel(i, zero, sf::Color::Black);
            image.setPixel(zero + cell_size - 1, i, sf::Color::Black);
            image.setPixel(i, zero + cell_size - 1, sf::Color::Black);
        }
    }

    //отрисовываем линии в текстуру
    sf::Texture texture;
    if (!texture.loadFromImage(image))
        return EXIT_FAILURE;

    sf::RenderTexture rt_text;
    if (!rt_text.create(win_size, win_size))
        return EXIT_FAILURE;
    sf::Sprite background;
    background.setTexture(texture);

    sf::Text text("1", font, font_size);
    text.setFillColor(sf::Color::Black);
    rt_text.draw(background);

    sf::Sprite s_field(rt_text.getTexture());

    sf::CircleShape circle;
    circle.setRadius(cell_size / 2 - block_offset);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(1);

    sf::RectangleShape line;
    line.setSize(sf::Vector2f(cell_size / 2 + (line_thickness / 2), line_thickness));
    line.setFillColor(sf::Color::Black);

    ///////отрисовываем цифры в текстуру
    //sf::Texture text_texture;
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //        if (field[i][j] > 0)
    //        {
    //            int offset = (field[i][j] > 9) ? 9 : 16;
    //            text.setString(std::to_string(field[i][j]));
    //            text.setPosition(j * cell_size + offset, i * cell_size + 10);
    //            rt_text.draw(text);
    //        }
    //    }
    //}
    //rt_text.display();

    ////отрисовываем блоки
    //sf::Image img_block;
    //img_block.create(cell_size - block_offset * 2, cell_size - block_offset * 2, sf::Color::Red);
    //sf::Texture t_block;
    //if (!t_block.loadFromImage(img_block))
    //    return EXIT_FAILURE;
    //sf::Sprite sp_block(t_block);

    bool game_is_over = false;
    sf::Text gameover("You win", font, font_size_gameover);
    gameover.setFillColor(sf::Color::Green);
    gameover.setOutlineColor(sf::Color::Black);
    gameover.setOutlineThickness(2.0);
    gameover.setPosition(win_size / 2 - font_size_gameover * 34 / 10 / 2, win_size / 2 - font_size_gameover);

    ///////////////////// MAIN GAME LOOP //////////////////////////////////
    ///////////////////// Главный Игровой Цикл //////////////////////////////////

    while (window.isOpen())
    {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            // Если нажат крестик - закрыть
            if (event.type == sf::Event::Closed)
                window.close();
            // Если нажата ЛКМ
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Если игра закончена начать сначала
                    if (game_is_over)
                    {
                        answer_to_field(answer, field, n);
                        game_is_over = false;
                    }
                    // Иначе кликнуть на клетку
                    else
                    {
                        int i = event.mouseButton.y / cell_size;
                        int j = event.mouseButton.x / cell_size;
                        field[i][j] = next_cell_state(field[i][j]);
                        //проверяем условия победы
                        if (check_ans(answer, field, n))
                        {
                            game_is_over = true;
                        }
                    }
                }
            }
        }

        // Очищаем окно
        window.clear();

        //отрисовываем линии и цифры
        window.draw(s_field);

        //отрисовываем блоки
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (field[i][j] >= CELL_WHITE)
                {
                    circle.setPosition(j * cell_size + block_offset, i * cell_size + block_offset);
                    circle.setFillColor(sf::Color::White);
                    window.draw(circle);
                }
                else if (field[i][j] >= CELL_BLACK)
                {
                    circle.setPosition(j * cell_size + block_offset, i * cell_size + block_offset);
                    circle.setFillColor(sf::Color::Color(100, 100, 100));
                    window.draw(circle);
                }

                int line_type = field[i][j] % 10;
                
                if (line_type > LINE_NONE)
                {
                    //line_right
                    if (line_type == LINE_HOR || line_type == LINE_NE || line_type == LINE_SE)
                    {
                        line.setPosition(j * cell_size + cell_size / 2 - line_thickness / 2, i * cell_size + cell_size / 2 - line_thickness / 2);
                        line.setRotation(0);
                        window.draw(line);
                    }
                    //line_left
                    if (line_type == LINE_HOR || line_type == LINE_NW || line_type == LINE_SW)
                    {
                        line.setPosition(j * cell_size, i * cell_size + cell_size / 2 - line_thickness / 2);
                        line.setRotation(0);
                        window.draw(line);
                    }
                    //line_up
                    if (line_type == LINE_VER || line_type == LINE_NE || line_type == LINE_NW)
                    {
                        line.setPosition(j * cell_size + cell_size / 2 - line_thickness / 2, i * cell_size + cell_size / 2 + line_thickness / 2);
                        line.setRotation(-90);
                        window.draw(line);
                    }
                    //line_down
                    if (line_type == LINE_VER || line_type == LINE_SE || line_type == LINE_SW)
                    {
                        line.setPosition(j * cell_size + cell_size / 2 - line_thickness / 2, i * cell_size + cell_size );
                        line.setRotation(-90);
                        window.draw(line);
                    }
                }
                
            }
        }
        //если игра окончена - отрисовываем надпись
        if (game_is_over)
        {
            window.draw(gameover);
        }
        window.display();
    }
    return EXIT_SUCCESS;
}