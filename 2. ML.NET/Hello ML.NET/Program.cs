using Microsoft.ML;
using Microsoft.ML.Data;

namespace Starter;

public class HouseData
{
    public float Size { get; set; }
    public float Price { get; set; }
}

public class Prediction
{
    [ColumnName("Score")]
    public float Price { get; set; }
}

public class Program
{
    static void Main()
    {
        //Create ML.NET context
        MLContext context = new MLContext();

        // Create training data
        HouseData[] data =
        {
            new HouseData { Size = 1.1f, Price = 1.2f },
            new HouseData { Size = 1.9f, Price = 2.3f },
            new HouseData { Size = 2.8f, Price = 3.0f },
            new HouseData { Size = 3.4f, Price = 3.7f }
        };

        // Load training data
        IDataView trainingData = context.Data.LoadFromEnumerable(data);

        // Process the data
        var pipeline = context.Transforms
            .Concatenate("Features", new[] { "Size" })
            .Append
            (
                context.Regression.Trainers.Sdca(labelColumnName: "Price", maximumNumberOfIterations: 100)
            );

        // Train a model
        ITransformer model = pipeline.Fit(trainingData);

        // Make a prediction
        var house = new HouseData { Size = 2.5f };
        var predictionEngine = context.Model.CreatePredictionEngine<HouseData, Prediction>(model);
        var prediction = predictionEngine.Predict(house);

        Console.WriteLine(prediction?.Price);
        Console.ReadKey();
    }
}