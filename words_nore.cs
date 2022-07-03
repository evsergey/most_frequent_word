using System.Globalization;

string text = File.ReadAllText("ClarissaHarlowe.txt");

int pos = 0;
bool is_latin_alpha(char ch) => (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
ReadOnlySpan<char> next_word()
{
    for (; pos < text.Length && !is_latin_alpha(text[pos]); pos++) ;
    int start = pos;
    for (; pos < text.Length && is_latin_alpha(text[pos]); pos++) ;
    return text.AsSpan(start, pos - start);
}
DateTime t0 = DateTime.UtcNow;

Dictionary<string, int> d = new();
for (; ; )
{
    var word_span = next_word();
    if (word_span.Length == 0)
        break;
    if (word_span.Length > 3)
    {
        string word = word_span.ToString();
        if (d.TryGetValue(word, out int count))
            d[word] = count + 1;
        else
            d.Add(word, 1);
    }
}
var max_word = d.MaxBy(x => x.Value);
Console.WriteLine($"Most frequent: \"{max_word.Key}\", count: {max_word.Value}");
Console.WriteLine($"Elapsed: {(DateTime.UtcNow - t0).TotalSeconds.ToString(CultureInfo.InvariantCulture.NumberFormat)}");
