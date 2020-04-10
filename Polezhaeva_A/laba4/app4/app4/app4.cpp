#include <iostream>
#include <iomanip>

int main()
{
    srand(time(0));
    int H, W, tree, count;
    bool flag = true;
    std::cout << "Enter Height: "; std::cin >> H;//вводвысоты
    std::cout << "Enter Width: "; std::cin >> W;//вводширины
    std::cout << "Enter trees quantity: "; std::cin >> tree;//вводдеревьев
    std::cout << "\n\n";
    char** M = new char * [H]; //создание 2-мерного массива чар
    for (int i = 0; i < H; i++)
        M[i] = new char[W];

    count = H * W;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            M[i][j] = '.';
        }
    }
    int* numOfTree = new int(1);
    while (count >= 0)
    {
        int i_index, j_index;
        std::cout << "Tree number " << *numOfTree << "\n\n";
        std::cout << "Enter the X coordinate for the tree ";
        std::cin >> j_index;
        std::cin.ignore(1024, '\n');
        std::cout << "Enter the Y coordinate for the tree ";
        std::cin >> i_index;
        std::cin.ignore(1024, '\n');
        std::cout << "\n";
        
        flag = false;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (i == i_index && j == j_index)
                {
                    if (M[i][j] != 'O')
                    {
                        flag = true;
                        M[i][j] = 'O';
                        tree--;
                        *numOfTree += 1;
                        break;
                    }
                    else
                    {
                        std::cout << "There is already a tree at this place" << std::endl;
                        count++;
                        break;
                    }
                }
            }
        }
        if (tree == 0) {
            delete numOfTree;
            break;
        }
            
        count--;
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (M[i][j] == 'O')
            {
                count = 0;
                if (i - 1 >= 0)
                {
                    if (i - 2 >= 0)
                    {
                        if (M[i - 2][j] == '#')
                            count++;
                        if (j - 1 >= 0)
                        {
                            if (M[i - 2][j - 1] == '#')
                                count++;
                        }
                        if (j + 1 < W)
                        {
                            if (M[i - 2][j + 1] == '#')
                                count++;
                        }
                    }
                    if (j + 1 < W)
                    {
                        if (M[i - 1][j + 1] == '#' || M[i][j + 1] == '#')
                            count++;
                    }
                    if (j - 1 >= 0)
                    {
                        if (M[i - 1][j - 1] == '#' || M[i][j - 1] == '#')
                            count++;
                    }
                    if (count == 0)
                    {
                        M[i - 1][j] = '#';
                        j++;
                        if (j == W)
                            break;
                    }
                }
            }
            if (M[i][j] == 'O')
            {
                count = 0;
                if (j + 1 < W)
                {
                    if (j + 2 < W)
                    {
                        if (M[i][j + 2] == '#')
                            count++;
                        if (i - 1 >= 0)
                        {
                            if (M[i - 1][j + 2] == '#')
                                count++;
                        }
                        if (i + 1 < H)
                        {
                            if (M[i + 1][j + 2] == '#')
                                count++;
                        }
                    }
                    if (i - 1 >= 0)
                    {
                        if (M[i - 1][j + 1] == '#' || M[i - 1][j] == '#')
                            count++;
                    }
                    if (i + 1 < H)
                    {
                        if (M[i + 1][j + 1] == '#' || M[i + 1][j] == '#')
                            count++;
                    }
                    if (count == 0)
                    {
                        M[i][j + 1] = '#';
                        j++;
                        if (j == W)
                            break;
                    }
                }
            }
            if (M[i][j] == 'O')
            {
                count = 0;
                if (i + 1 < H)
                {
                    if (i + 2 < H)
                    {
                        if (M[i + 2][j] == '#')
                            count++;
                        if (j - 1 >= 0)
                        {
                            if (M[i + 2][j - 1] == '#')
                                count++;
                        }
                        if (j + 1 < W)
                        {
                            if (M[i + 2][j + 1] == '#')
                                count++;
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        if (M[i + 1][j - 1] == '#' || M[i][j - 1] == '#')
                            count++;
                    }
                    if (j + 1 < W)
                    {
                        if (M[i + 1][j + 1] == '#' || M[i][j + 1] == '#')
                            count++;
                    }
                    if (count == 0)
                    {
                        M[i + 1][j] = '#';
                        j++;
                        if (j == W)
                            break;
                    }
                }
            }
            if (M[i][j] == 'O')
            {
                count = 0;
                if (j - 1 >= 0)
                {
                    if (j - 2 >= 0)
                    {
                        if (M[i][j - 2] == '#')
                            count++;
                        if (i - 1 >= 0)
                        {
                            if (M[i - 1][j - 2] == '#')
                                count++;
                        }
                        if (i + 1 < H)
                        {
                            if (M[i + 1][j - 2] == '#')
                                count++;
                        }
                    }
                    if (i - 1 >= 0)
                    {
                        if (M[i - 1][j - 1] == '#' || M[i - 1][j] == '#')
                            count++;
                    }
                    if (i + 1 < H)
                    {
                        if (M[i + 1][j - 1] == '#' || M[i + 1][j] == '#')
                            count++;
                    }
                    if (count == 0)
                    {
                        M[i][j - 1] = '#';
                        j++;
                        if (j == W)
                            break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (M[j][i] == '#')
                count++;
        }
        std::cout << std::setw(4) << count;
        count = 0;
    }
    std::cout << "\n";

    for (int i = 0; i < W; i++)
        std::cout << std::setw(4) << "====";

    std::cout << "\n";

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            std::cout << std::setw(4) << M[i][j];
        }
        for (int j = 0; j < W; j++)
        {
            if (M[i][j] == '#')
                count++;
        }
        std::cout << "  -- " << count;
        count = 0;
        std::cout << "\n\n";
    }

    for (int i = 0; i < H; i++)
        delete[] M[i];

    delete[] M;

    system("pause");
    return 0;
}
