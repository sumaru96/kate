# KATE CLI TOOL v1.0.0

Kate is a lightweight and fast CLI utility for creating, building, and running Java and Kotlin projects without IDEs. It automatically manages the Gradle Wrapper for you.

## License
Distributed under the GPL-3.0 License.

## Commands
* `kate new [path] [--java / --kotlin]` - Create a new project.
* `kate run` - Build and run via Gradle.
* `kate run -u / --unrebuild` - Instant run compiled .jar directly (Skips Gradle).
* `kate run -r / --rebuild` - Force Gradle rebuild and run.
* `kate build` - Just compile the project.
* `kate help` - Show help menu.