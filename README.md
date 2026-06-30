*This project has been created as part of the 42 curriculum by febranda.*

# Philosophers

## Description

**Philosophers** is a 42 School project about concurrent programming. The goal is to
solve a classic synchronization problem — the *Dining Philosophers Problem* — using
threads and mutexes in C.

A number of philosophers sit around a round table. Each one alternates between three
states: eating, thinking, and sleeping. To eat, a philosopher must pick up both the fork
to their left and the fork to their right, since there is exactly one fork between every
pair of philosophers. If a philosopher does not start eating before their `time_to_die`
runs out, they starve and the simulation stops.

This project focuses on:

- Creating and managing threads with the POSIX `pthread` library.
- Protecting shared resources (forks, simulation state, meal data) with mutexes.
- Avoiding deadlocks and data races while keeping the simulation accurate and
  responsive.
- Producing correctly ordered, non-overlapping log output under concurrency.

Only the **mandatory part** of the project (threads + mutexes) is covered by this
repository.

## Instructions

### Compilation

```bash
cd philo
make
```

This builds the `philo` executable using `cc` with the `-Wall -Wextra -Werror` flags,
as required by the project rules.

Other available rules:

```bash
make clean   # remove object files
make fclean  # remove object files and the executable
make re      # fclean + all
```

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) sitting at the table. |
| `time_to_die` | Time in ms before a philosopher dies if they haven't started eating. |
| `time_to_eat` | Time in ms a philosopher spends eating. |
| `time_to_sleep` | Time in ms a philosopher spends sleeping. |
| `number_of_times_each_philosopher_must_eat` *(optional)* | If given, the simulation stops once every philosopher has eaten this many times. |

Example:

```bash
./philo 5 800 200 200
./philo 4 410 200 200 7
```

Each state change is printed as:

```
timestamp_in_ms philosopher_id message
```

where the message is one of: `has taken a fork`, `is eating`, `is sleeping`,
`is thinking`, or `died`.

## Resources

- `man pthread_create`, `man pthread_mutex_lock`, `man gettimeofday`, `man usleep`
- 42 School subject: *Philosophers*

### AI usage

- Reviewing and debugging the thread synchronization;
- Clarifying edge cases from the subject, such as handling a single philosopher and
  the optional `number_of_times_each_philosopher_must_eat` argument.
