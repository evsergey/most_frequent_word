using System.Globalization;
using System.Text.RegularExpressions;

string text = File.ReadAllText("ClarissaHarlowe.txt");

DateTime t0 = DateTime.UtcNow;

Regex re = new Regex(@"[^a-xzA-Z]+");
Dictionary<string, int> d = new();
foreach (string word in re.Split(text))
    if (word.Length > 3)
    {
        if (d.TryGetValue(word, out int count))
            d[word] = count + 1;
        else
            d.Add(word, 1);
    }
Console.WriteLine($"Total words: {d.Count}");
var max_word = d.MaxBy(x => x.Value);
Console.WriteLine($"Most frequent: \"{max_word.Key}\", count: {max_word.Value}");
Console.WriteLine($"Elapsed: {(DateTime.UtcNow - t0).TotalSeconds.ToString(CultureInfo.InvariantCulture.NumberFormat)}");

