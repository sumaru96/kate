# KATE CLI TOOL v1.0.2

Kate is a lightweight and fast CLI utility for creating, building, and running Java and Kotlin projects without IDEs. It automatically embeds and manages the Gradle Wrapper for you.

## License
Distributed under the GPL-3.0 License.

## Commands
* `kate new [path] [--java / --kotlin]` — Create a new project workspace (Kotlin is default).
* `kate init` — Initialize Kate in the current working directory. Automatically detects the folder name and generates a `kate.toml` config.
* `kate run` — Build and run the project via Gradle.
* `kate run -u / --unrebuild` — Instant run. Launches the compiled `.jar` directly, skipping Gradle to save time.
* `kate run -r / --rebuild` — Force Gradle to re-assemble and run.
* `kate run -a / --args "arguments"` — Pass arguments directly to your application. **Supports unlimited arguments using quotes!**
* `kate build` — Just compile the project and create a production package.
* `kate clean` — Clean the project build directories and temporary files.
* `kate help / -h / --help` — Show the help menu with all available commands.

## Advanced Arguments Parsing 🚀
The arguments parser has been fully upgraded! 
* You can now pass **UNLIMITED** arguments to your application.
* Wrap your arguments in standard quotes (`""`) to pass complex strings, flags, or multiple words.

## Examples
```bash
# Create a new Java project
kate new my-app --java

# Initialize a project in an existing folder
cd my-existing-folder
kate init

# Run app instantly and pass multiple arguments via quotes
kate run -u -a "fast_boot active --debug-level=2"
