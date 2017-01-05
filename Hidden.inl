

//ф-ция обнуляет структуру;
void inline Set_Up_BChart(Bar &barchart)
{
    barchart.BarsLength = 0;
    barchart.BarsNames = 0;
    barchart.ChartBlock = '|';
    barchart.NumBars = 0;
}
//ф-ция удаляет структуру;
void inline Delete_A_BChart(Bar &barchart)
{
    if (barchart.NumBars)
    {
        delete[] barchart.BarsLength;
        barchart.BarsLength = 0;
        delete[] barchart.BarsNames;
        barchart.BarsNames = 0;
    }
    barchart.NumBars = 0;
}