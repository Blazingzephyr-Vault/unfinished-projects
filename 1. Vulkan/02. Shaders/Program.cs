
using Silk.NET.Maths;
using Silk.NET.Windowing;
using Silk.NET.Windowing.Glfw;

// Register the platform — so that the NativeAOT-compiled application doesn't
// throw System.NullReferenceException
GlfwWindowing.RegisterPlatform();

// Specify window creation options using Silk's GLFW windowing system
var options = WindowOptions.DefaultVulkan with
{
    Size = new Vector2D<int>(800, 600),
    Title = "01. Opening a Window"
};

// Create the window using specified options
var window = Window.Create(options);

// Register the event which displays elapsed time for 2 seconds before quitting
window.Closing += () =>
{
    window.Title = "Elapsed: " + window.Time;
    Thread.Sleep(2000);
};

// Initialize the window
window.Initialize();

// Throw if Vulkan isn't supported
if (window.VkSurface is null)
{
    throw new InvalidOperationException("Windowing platform doesn't support Vulkan.");
}

// Display the window
window.Run();
window.Dispose();