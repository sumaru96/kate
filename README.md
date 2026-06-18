# KATE CLI TOOL v1.0.2

Kate is a lightweight and fast CLI utility for creating, building, and running Java and Kotlin projects without IDEs. It automatically manages the Gradle Wrapper for you.

## License
Distributed under the GPL-3.0 License.

## Commands
* `kate new [path] [--java / --kotlin]` — Create a new project workspace (Kotlin is default).
* `kate run` — Build and run the project via Gradle.
* `kate run -u / --unrebuild` — Instant run. Launches the compiled `.jar` directly, skipping Gradle to save time.
* `kate run -r / --rebuild` — Force Gradle to re-assemble and run.
* `kate run -a / --args [argument]` — Pass a single argument directly to your application.
* `kate build` — Just compile the project and create a production package.
* `kate clean` — Clean the project build directories and temporary files.
* `kate help` — Show the help menu with all available commands.

## Important Note on Arguments ⚠️
Currently, the arguments parser is in a lightweight state.
* Pass **strictly ONE** argument.
* Do **NOT** use quotes, parentheses, or brackets (`""`, `()`, `[]`).
* Passing multiple words or quotes will break the command line execution. Advanced parsing will be added in future updates.

## Examples
```bash
# Create a new Java project
kate new my-app --java

# Run app instantly with a SINGLE argument without quotes
kate run -u -a test_mode